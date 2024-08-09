#include <iostream>
#include <future>
#include <chrono>
#include <thread>
#include <functional>
#include <random>

// TODO: Create a function named 'execute' that executes a given packaged task in a separate thread.

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
