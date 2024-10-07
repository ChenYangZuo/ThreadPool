//
// Created by zuo-c on 2024/10/7.
//

#ifndef THREADPOOL_THREADPOOL_H
#define THREADPOOL_THREADPOOL_H

#include <vector>
#include <thread>
#include <functional>
#include <queue>
#include <string>

using namespace std;

enum class ThreadPoolStatus {
    STATUS_INIT = 0,
    STATUS_RUNNING,
    STATUS_STOPPING,
    STATUS_STOPPED
};

class Task {

public:
    Task(){

    }

    ~Task(){

    }

private:
    std::string m_name;
    std::function<void()> m_callback;
    int m_priority;
};


class ThreadPool {

public:
    ThreadPool(){

    }

    ~ThreadPool(){

    }

    int addTask(Task task){
        return 0;
    }

    void start(){

    }

    void stop(){

    }

private:
    ThreadPoolStatus m_status;

    std::vector<std::thread> m_coreThreads;
    std::vector<std::thread> m_dynamicThreads;

    std::queue<Task> m_taskQueue;

    size_t m_coreThreadNum;
    size_t m_dynamicThreadMaxNum;
    size_t m_dynamicThreadCurrentNum;

    size_t m_queueMaxSize;


};


#endif //THREADPOOL_THREADPOOL_H
