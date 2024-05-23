#include <iostream>
#include <vector>
#include <algorithm>  // 包含heap操作的算法

int main() {
    std::vector<int> vec = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

    // 创建一个heap
    std::make_heap(vec.begin(), vec.end());
    std::cout << "Initial heap: ";
    for (int n : vec) std::cout << n << " ";
    std::cout << std::endl;

    // 添加一个新元素到heap中
    vec.push_back(7);
    std::push_heap(vec.begin(), vec.end());
    std::cout << "Heap after push_heap: ";
    for (int n : vec) std::cout << n << " ";
    std::cout << std::endl;

    // 取出heap中的最大元素
    std::pop_heap(vec.begin(), vec.end());
    int max = vec.back();
    vec.pop_back();
    std::cout << "Max element: " << max << std::endl;
    std::cout << "Heap after pop_heap: ";
    for (int n : vec) std::cout << n << " ";
    std::cout << std::endl;

    // 对heap进行排序
    std::sort_heap(vec.begin(), vec.end());
    std::cout << "Sorted heap: ";
    for (int n : vec) std::cout << n << " ";
    std::cout << std::endl;

    return 0;
}
