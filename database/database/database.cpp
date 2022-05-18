#include "database.h"
#include "../../config/config.h"

#include <functional>

namespace database {
    Database& Database::get() {
        static Database instance;
        return instance;
    }

    Poco::Data::Session Database::createSession() {
        return Poco::Data::Session(Poco::Data::SessionFactory::instance().create(Poco::Data::MySQL::Connector::KEY, m_connectionString));
    }
    
    size_t Database::getMaxShards() {
		return 2;
	}

    std::string Database::shardingHint(std::string login) {
		size_t shardNumber = std::hash<std::string>{}(login) % getMaxShards();

		std::string result = "-- sharding:";
        result += std::to_string(shardNumber);
		return result;
	}

	std::vector<std::string> Database::getAllHints() {
		std::vector<std::string> results;
		for (size_t i = 0; i < getMaxShards(); ++i) {
			std::string shardName = "-- sharding:";
			shardName += std::to_string(i);
			results.push_back(shardName);
		}
		return results;
	}

	Database::Database() {
        m_connectionString += "host=";
        m_connectionString += Config::get().getHost();

		m_connectionString += ";port=";
		m_connectionString += Config::get().getPort();

		m_connectionString += ";user=";
        m_connectionString += Config::get().getLogin();

        m_connectionString += ";db=";
        m_connectionString += Config::get().getDatabase();

        m_connectionString += ";password=";
        m_connectionString += Config::get().getPassword();

        Poco::Data::MySQL::Connector::registerConnector();
    }
}