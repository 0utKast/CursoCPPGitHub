#include <iostream>
#include <mutex>
#include <string>

class Logger {
public:
	static Logger& instance() {
		static Logger instance_;
		return instance_;
	}

    void logError(const std::string& msg) {
        std::lock_guard<std::mutex> guard(lock_);
        std::cerr << "ERROR: " << msg << std::endl;
        ++error_count_;
    }

    void logWarning(const std::string& msg) {
        std::lock_guard<std::mutex> guard(lock_);
        std::cerr << "ADVERTENCIA: " << msg << std::endl;
        ++warning_count_;
    }

    void logInfo(const std::string& msg) {
        std::lock_guard<std::mutex> guard(lock_);
        std::cout << "INFO: " << msg << std::endl;
        ++info_count_;
    }

    size_t getErrorCount() const {
        return error_count_;
    }

    size_t getWarningCount() const {
        return warning_count_;
    }

    size_t getInfoCount() const {
        return info_count_;
    }
private:
    Logger() : error_count_(0), warning_count_(0), info_count_(0) {}
    ~Logger() {}
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
    Logger(Logger&&) = delete;
    Logger& operator=(Logger&&) = delete;

    std::mutex lock_;
    size_t error_count_;
    size_t warning_count_;
    size_t info_count_;
};






