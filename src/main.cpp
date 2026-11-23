// main.cpp — entry point. Wires config and subsystems together.

#include "keypoolrotator/settings.h"
#include "keypoolrotator/pool.h"
#include "keypoolrotator/proxy.h"
#include "keypoolrotator/cooldowns.h"
#include <csignal>
#include <memory>

namespace { std::atomic<bool> g_running{true}; void on_signal(int) { g_running.store(false); } }

int main(int argc, char** argv) {
    std::signal(SIGINT, on_signal);
    std::signal(SIGTERM, on_signal);

    keypoolrotator::Settings settings = keypoolrotator::Settings::load_default();
    keypoolrotator::Pool pool(settings.store_path);
    keypoolrotator::Proxy proxy(settings.store_path);
    keypoolrotator::Cooldowns cooldowns(settings.store_path);
    std::fprintf(stderr, "[key-pool-rotator] ready\n");

    while (g_running.load()) {
        // main loop: pump subsystems
        break;
    }
    return 0;
}
