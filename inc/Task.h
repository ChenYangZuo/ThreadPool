//
// Created by zuo-c on 2024/10/7.
//

#ifndef THREADPOOL_TASK_H
#define THREADPOOL_TASK_H


#include <iostream>
#include <functional>
#include <tuple>
#include <utility>
#include <stdexcept>

class Task {
public:
    // 构造函数，接收函数、参数以及优先级
    template<typename Func, typename... Args>
    Task(int priority, Func&& func, Args&&... args)
            : m_function(std::bind(std::forward<Func>(func), std::forward<Args>(args)...)) {

        this->setPriority(priority);
    }

    // 执行任务
    void execute() {
        m_function();
    }

    // 获取优先级
    int getPriority() const {
        return m_priority;
    }

    // 设置优先级（0-99）
    void setPriority(int priority) {
        if (priority < 0 || priority > 99) {
            throw std::out_of_range("Priority must be between 0 and 99");
        }
        m_priority = priority;
    }

    // 设置任务函数（支持可变参数）
    template<typename Func, typename... Args>
    void setFunction(Func&& func, Args&&... args) {
        m_function = std::bind(std::forward<Func>(func), std::forward<Args>(args)...);
    }

private:
    int m_priority{}; // 任务的优先级（0-99）
    std::function<void()> m_function; // 存储任务的函数和参数
};


#endif //THREADPOOL_TASK_H
