//
// Created by zuo-c on 2024/10/7.
//
#include <iostream>

#include "inc/Task.h"

int main() {
    try {
        // 创建优先级为5的任务
        Task task(5, [](int a, int b) {
            std::cout << "Sum: " << a + b << std::endl;
        }, 2, 3);

        // 执行任务
        task.execute();

        // 输出优先级
        std::cout << "Priority: " << task.getPriority() << std::endl;

        // 创建一个无效的任务，优先级超出范围
        Task invalidTask(150, []() {
            std::cout << "This task will not be created" << std::endl;
        });

    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}