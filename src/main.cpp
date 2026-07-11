#include "LRUCache.hpp"
#include <chrono>
#include <iostream>
#include <iomanip>

int main() {
    std::cout << "====================================================\n";
    std::cout << "🚀 PRODUCTION CORE: HIGH-PERFORMANCE IN-MEMORY CACHE 🚀\n";
    std::cout << "====================================================\n\n";

    LRUCache cache(2);

    auto start = std::chrono::high_resolution_clock::now();

    std::cout << "[System Log]: Executing batch sequential operations...\n";
    cache.write("session_token_A", 1001);
    cache.write("session_token_B", 2002);
    
    cache.write("session_token_C", 3003); 

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> elapsed = end - start;

    std::cout << "[System Log]: Operations executed in: " << std::fixed << std::setprecision(2) << elapsed.count() << " us\n\n";

    std::cout << "⚙️ VERIFICATION METRICS:\n";
    std::cout << "  - Cache Read 'session_token_C': " << cache.read("session_token_C") << " (Active)\n";
    std::cout << "  - Cache Read 'session_token_B': " << cache.read("session_token_B") << " (Active)\n";
    std::cout << "  - Cache Read 'session_token_A': " << cache.read("session_token_A") << " (-1 nghĩa là đã tự động giải phóng thành công!)\n";
    std::cout << "====================================================\n";

    return 0;
}
