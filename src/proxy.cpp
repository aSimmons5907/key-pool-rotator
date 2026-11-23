// proxy.cpp — part of key-pool-rotator.

#include "keypoolrotator/proxy.h"

#include <cstdio>

namespace keypoolrotator {

Proxy::Proxy(const std::string& config_path)
    : config_path_(config_path) {}

void Proxy::configure(const std::string& key, const std::string& value) {
    if (key == "verbose") verbose_ = (value == "true");
}

bool Proxy::run() {
    if (verbose_) std::fprintf(stderr, "[key-pool-rotator] proxy: run\n");
    // core logic lives here
    return true;
}

}  // namespace keypoolrotator
