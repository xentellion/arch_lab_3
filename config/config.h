#pragma once
#ifndef CONFIG_H
#define CONFIG_H

#include <string>

class Config {
public:
    static Config& get();

    std::string& port();
    std::string& host();
    std::string& login();
    std::string& password();
    std::string& database();
    std::string& cacheServers();

    const std::string& getPort() const;
    const std::string& getHost() const;
    const std::string& getLogin() const;
    const std::string& getPassword() const;
    const std::string& getDatabase() const;
    const std::string& getCacheServers() const;

private:
    Config() = default;
    
    std::string m_host;
    std::string m_port;
    std::string m_login;
    std::string m_password;
    std::string m_database;

    std::string m_cacheServers;
};

#endif // !CONFIG_H