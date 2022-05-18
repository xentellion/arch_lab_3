#include "config.h"

Config& Config::get() {
    static Config instance;
    return instance;
}

std::string& Config::port() {
    return m_port;
}

std::string& Config::host() {
    return m_host;
}

std::string& Config::login() {
    return m_login;
}

std::string& Config::password() {
    return m_password;
}

std::string& Config::database() {
    return m_database;
}

std::string& Config::cacheServers() {
    return m_cacheServers;
}

const std::string& Config::getPort() const {
    return m_port;
}

const std::string& Config::getHost() const {
    return m_host;
}

const std::string& Config::getLogin() const {
    return m_login;
}

const std::string& Config::getPassword() const {
    return m_password;
}

const std::string& Config::getDatabase() const {
    return m_database;
}

const std::string& Config::getCacheServers() const {
    return m_cacheServers;
}