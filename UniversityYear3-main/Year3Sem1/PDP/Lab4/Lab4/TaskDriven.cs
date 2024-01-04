using System;
using System.Collections.Generic;
using System.IO;
using System.Net.Sockets;
using System.Threading.Tasks;
using static Lab4.Util;

namespace Lab4
{
    public class TaskDriven
    {
        private const int BufferSize = 1024 / 2;
        private const string Type = "TaskDriven";
        private byte[] _dataBuffer;
        private readonly string _link;
        private Socket _socket;
        private int _contentLength;
        private string _result = "";
        private string _filename;
        private Dictionary<string, string> _headers;

        public TaskDriven(string link)
        {
            _link = link;
        }
        public Task Download()
        {
            TaskCompletionSource<IAsyncResult> taskCompletionSource = new TaskCompletionSource<IAsyncResult>();
            Tuple<Socket, string, string> info = null;
            PrepareGetParameters(_link, (ar, receivedInfo) =>
            {
                info = receivedInfo;
                taskCompletionSource.SetResult(ar);
            });

            return taskCompletionSource.Task.ContinueWith((previous) => OnConnectDone(previous.Result, info).Wait());
        }
        
        private Task OnConnectDone(IAsyncResult ar, Tuple<Socket, string, string> info)
        {
            TaskCompletionSource<IAsyncResult> taskCompletionSource = new TaskCompletionSource<IAsyncResult>();
            _socket = info.Item1;
            string request = info.Item2;
            _filename = info.Item3;
            
            _socket.EndConnect(ar);
            
            _socket.BeginSend(StringToBytes(request), 0, request.Length, SocketFlags.None, (ar) =>
            {
                taskCompletionSource.SetResult(ar);
            }, null);
            return taskCompletionSource.Task.ContinueWith(previous => OnSendDone(previous.Result).Wait());
        }

        private Task OnSendDone(IAsyncResult ar)
        {
            TaskCompletionSource<IAsyncResult> taskCompletionSource = new TaskCompletionSource<IAsyncResult>();
            var size = _socket.EndSend(ar);
            _dataBuffer = new byte[BufferSize];
            _socket.BeginReceive(_dataBuffer, 0, BufferSize, SocketFlags.None, (ar) => taskCompletionSource.SetResult(ar), null);
            return taskCompletionSource.Task
                .ContinueWith((previous) => OnInitialBytesReceived(previous.Result).Wait());
        }
        
        private Task OnInitialBytesReceived(IAsyncResult ar)
        {
            TaskCompletionSource<IAsyncResult> taskCompletionSource = new TaskCompletionSource<IAsyncResult>();
            var size = _socket.EndReceive(ar);
            if (size > 0)
            {
                _headers = ParseFirstRequest(BytesToString(_dataBuffer));
                _contentLength = int.Parse(_headers["Content-Length"]);
                _result += BytesToString(_dataBuffer);
                if (size == BufferSize)
                {
                    Array.Clear(_dataBuffer, 0, BufferSize);
                    _socket.BeginReceive(_dataBuffer, 0, BufferSize, SocketFlags.None, (ar) =>
                    {
                        taskCompletionSource.SetResult(ar);
                    }, null);
                }
                else
                {
                    SaveToFile();
                    taskCompletionSource.SetResult(null);
                }
            }
            else
            {
                SaveToFile();
                taskCompletionSource.SetResult(null);
            }
            Console.WriteLine(Type + " - " + _filename + ": " + BeautifySize(_contentLength));
            return taskCompletionSource.Task.ContinueWith((task) =>
            {
                if (task.Result != null)
                {
                    RepeatedReceive(task.Result).Wait();
                }
            });
        }

        private Task RepeatedReceive(IAsyncResult ar)
        {
            TaskCompletionSource<IAsyncResult> taskCompletionSource = new TaskCompletionSource<IAsyncResult>();
            var size = _socket.EndReceive(ar);
            if (size > 0)
            {
                _result += BytesToString(_dataBuffer);
                if (size == BufferSize)
                {
                    Array.Clear(_dataBuffer, 0, BufferSize);
                    _socket.BeginReceive(_dataBuffer, 0, BufferSize, SocketFlags.None, (ar) => taskCompletionSource.SetResult(ar), null);
                }
                else
                {
                    SaveToFile();
                    taskCompletionSource.SetResult(null);
                }
            }
            else
            {
                SaveToFile();
                taskCompletionSource.SetResult(null);
            }

            return taskCompletionSource.Task.ContinueWith((task) =>
            {
                if (task.Result != null)
                {
                    RepeatedReceive(task.Result).Wait();
                }
            });
        }

        private void SaveToFile()
        {
            if (_filename.Length > 0)
            {
                File.WriteAllText("../../../downloads/" + Type + "_" + _filename, _result);
            }
        }
    }
}