using System;
using System.Collections.Generic;
using System.IO;
using System.Net.Sockets;
using static Lab4.Util;

namespace Lab4
{
    public class EventDriven
    {
        
     private const int BufferSize = 1024 / 2;
        private const string Type = "EventDriven";
        
        private byte[] _dataBuffer;
        private readonly string _link;
        private readonly Action _finishedAction;
        private Socket _socket;
        private int _contentLength;
        private string _result = "";
        private string _filename;
        private Dictionary<string, string> _headers;

        public EventDriven(string link, Action finished)
        {
            _link = link;
            _finishedAction = finished;
        }
        public void Download()
        {
            PrepareGetParameters(_link, OnConnectDone); 
        }

        private void OnConnectDone(IAsyncResult ar, Tuple<Socket, string, string> info)
        {
            _socket = info.Item1;
            string request = info.Item2;
            _filename = info.Item3;
            
            _socket.EndConnect(ar);
            
            _socket.BeginSend(StringToBytes(request), 0, request.Length, SocketFlags.None, OnSendDone, null);
        }
        private void OnSendDone(IAsyncResult ar)
        {
            var size = _socket.EndSend(ar);
            _dataBuffer = new byte[BufferSize];
            _socket.BeginReceive(_dataBuffer, 0, BufferSize, SocketFlags.None, OnInitialBytesReceived, null);
        }
        
        private void OnInitialBytesReceived(IAsyncResult ar)// initial read from html into file
        {
            var size = _socket.EndReceive(ar);
            if (size > 0)
            {
                _headers = ParseFirstRequest(BytesToString(_dataBuffer));
                _contentLength = int.Parse(_headers["Content-Length"]);
                _result += BytesToString(_dataBuffer);
                if (size == BufferSize)
                {
                    Array.Clear(_dataBuffer, 0, BufferSize);
                    _socket.BeginReceive(_dataBuffer, 0, BufferSize, SocketFlags.None, RepeatedReceive,
                        null);
                }
                    
                else SaveToFile();
            }
            else
                SaveToFile();
            Console.WriteLine(Type + " - " + _filename + ": " + BeautifySize(_contentLength));
        }

        private void RepeatedReceive(IAsyncResult ar)// repeated task until html is done 
        {
            var size = _socket.EndReceive(ar);
            if (size > 0)
            {
                _result += BytesToString(_dataBuffer);
                if (size == BufferSize)
                {
                    Array.Clear(_dataBuffer, 0, BufferSize);
                    _socket.BeginReceive(_dataBuffer, 0, BufferSize, SocketFlags.None, RepeatedReceive, null);
                }
                else
                    SaveToFile();
            }
            else
                SaveToFile();
        }

        private void SaveToFile()
        {
            
            if (_filename.Length > 0)
            {
                File.WriteAllText("../../../downloads/" + Type + "_" + _filename, _result);
            }
            _finishedAction();
        }
        
    }
}