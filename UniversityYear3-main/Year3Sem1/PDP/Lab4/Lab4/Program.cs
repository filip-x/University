using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Threading;
using System.Threading.Tasks;

namespace Lab4
{
    class Program
    {
        private static List<string> links = new List<string>();

        private static void FillLinks()
        {
            links.Add("http://www.itsecgames.com/training.htm");
            links.Add("http://www.cs.ubbcluj.ro/~rlupsa/edu/pdp/lab-4-futures-continuations.html");
            links.Add("http://www.cs.ubbcluj.ro/~rlupsa/edu/pdp/lecture-8-mpi.html");
            links.Add("http://www.cs.ubbcluj.ro/~rlupsa/edu/pdp/progs/matrix-mpi.cpp");
        }
        
        private static void  RunEventDriven()
        {
            int done = 0;
            var stopWatch = new Stopwatch();
            stopWatch.Start();
            foreach (var link in links)
            {
                new EventDriven(link, () =>
                {
                    Interlocked.Increment(ref done);
                }).Download();
            }

            while (done < links.Count)// same as whil true =))))
            {
                
            }
            stopWatch.Stop();
            Console.WriteLine(stopWatch.Elapsed.TotalSeconds+ "took EventDriven to complete. ");
        }

        private static void RunTaskDriven()
        {
            var stopWatch = new Stopwatch();
            Task[] tasks = new Task[links.Count];
            stopWatch.Start();
            for(int i=0;i<links.Count;i++)
            {
                tasks[i] = new TaskDriven(links[i]).Download();
            }

            Task.WaitAll(tasks);
            stopWatch.Stop();
            Console.WriteLine(stopWatch.Elapsed.TotalSeconds+" took TaskDriven to complete. ");
        }
        
        private static async Task RunAsyncDriven()
        {
            var stopWatch = new Stopwatch();
            Task[] tasks = new Task[links.Count];
            stopWatch.Start();
            for (int i = 0; i < links.Count; i++)
            {
                tasks[i] = new AsyncDriven(links[i]).Download();
            }

            await Task.WhenAll(tasks);
            stopWatch.Stop();
            Console.WriteLine(stopWatch.Elapsed.TotalSeconds+"took AsyncDriven to complete. ");
        }

        static void Main(string[] args)
        {
            FillLinks();
            RunEventDriven();
            RunTaskDriven();
            RunAsyncDriven().Wait();
        }
    }
}