using System;
using System.Collections.Generic;
using System.IO;
using System.Net;
using System.Net.Sockets;

namespace Lab4
{
    public class Util
    {
        public static void PrepareGetParameters(string url, Action<IAsyncResult, Tuple<Socket, string, string>> beginConnect)
        {
            // Eliminating prefix
            if (url.StartsWith("http://"))
                url = url.Replace("http://", "");
            if (url.StartsWith("https://"))
                url = url.Replace("https://", "");
            
            // getting address and file
            var pos = url.IndexOf("/", StringComparison.Ordinal);
            string address, resource, filename;
            if (pos.Equals(-1))
            {
                resource = "/";
                address = url;
            }
            else
            {
                resource = url[pos..];// path to the file ( if we have any)
                address = url[..pos];// main address
            }

            pos = url.LastIndexOf("/", StringComparison.Ordinal);
            filename = pos.Equals(-1) ? "" : url[(pos + 1)..];
            filename = filename.Replace(" ", "_");
            var getString = "GET " + resource + " HTTP/1.1\r\nHost: " + address + "\r\n\r\n\r\n";
            
            // preparing the socket
            var socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            IPEndPoint connectEndpoint = new IPEndPoint(Dns.GetHostAddresses(address)[0], 80);
            
            socket.BeginConnect(connectEndpoint, (ar) =>
            {
                beginConnect(ar, new Tuple<Socket, string, string>(socket, getString, filename));
            }, null);
        }
        
        public static byte[] StringToBytes(string s)
        {
            return System.Text.Encoding.UTF8.GetBytes(s);
        }
        
        public static string BytesToString(byte[] b)
        {
            return System.Text.Encoding.UTF8.GetString(b);
        }

        public static Dictionary<string, string> ParseFirstRequest(string s)
        {
            StringReader reader = new StringReader(s);
            string line = reader.ReadLine();
            if (line != null)
            {
                line = reader.ReadLine();
            }

            Dictionary<String, String> headers = new Dictionary<string, string>();
            while (line != null && line.Length > 0)
            {
                var middle = line.IndexOf(':', StringComparison.Ordinal);
                var headerName = line[..middle].Trim();
                var headerValue = line[(middle + 1)..].Trim();
                headers[headerName] = headerValue;
                line = reader.ReadLine();
            }

            return headers;
        }

        public static string BeautifySize(int size)
        {
            string[] sizes = { "B", "KB", "MB", "GB", "TB" }; 
            var order = 0;
            float newSize = size;
            while (newSize >= 1024 && order < sizes.Length - 1) {
                order++;
                newSize = newSize/1024;
            }
            
            return $"{newSize:0.##} {sizes[order]}";
        }
    }
}