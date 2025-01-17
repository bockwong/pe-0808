#include <iostream>
#include <future>
#include <chrono>
#include <thread>
#include <functional>
#include <random>

/*
 Create a function named 'execute' that executes a given packaged task in a separate thread.
Arguments:
- t: a function that takes an integer as an argument and returns void
- load: an integer representing the workload. 
Returns: void
Details:
- Create a packaged_task with the given function
- Get the future from the task
- Start the task in a separate thread using move semantics
- Wait for the task to complete
- Join the worker thread
- Print "Task completed." after the task is done
Example:
execute(job, 10);
*/
void execute(std::function<void(int)> t, int load)
{
    std::packaged_task<void(int)> task(t);
    std::future<void> future = task.get_future();
    std::thread worker(std::move(task), load);
    worker.join();
    future.get();
    std::cout << "Task completed." << '\n';
}



int main()
{

    /*
    Create a lambda function named 'job' that simulates a workload by sleeping for a random time.
    Arguments:
    - workload: an integer representing the number of steps in the workload
    Returns: void
    Details:
    - For each step in the workload, sleep for a random time between 0.5 and 1.5 seconds
    - Print "Completed step #i" after each step
    Example:
    job(10);
    */
    auto job = [](int workload) -> void
    {
        for (int i = workload; i > 0; --i)
        {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_real_distribution<double> dis(0.5, 1.5);
            double sleepTime = dis(gen);
            std::this_thread::sleep_for(std::chrono::duration<double>(sleepTime));
            std::cout << "Completed step #" << i << '\n';
        }
    };

    const int steps = 10;
    execute(job, steps);

    return 0;
}
