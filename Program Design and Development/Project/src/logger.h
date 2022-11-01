//logger.h
/*******************************************************************************
 * Includes
 ******************************************************************************/ 
#include <iostream>
#include <fstream> 
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Logger is used to track information about the simulation and store it in a csv
 */ 
class Logger 
{
public:
	/**
	  * @brief Instance instantiates a new logger to be used without it having to be defined elsewhere
	  *
	  * @return an instance of the logger
	*/ 
	static Logger& Instance() 
	{
		static Logger instance;
		return instance;
	}
	/**
	  * @brief Log writes the data into the csv file
	  *
	  * @return void (data saved to csv)
	*/ 
	void Log(const double distance) 
	{
		std::ofstream dataFile;
		dataFile.open ("build/dataLog.csv", std::ofstream::app);
		dataFile << "Total Distance:,";
		dataFile << distance << ",\n";
		dataFile.close(); 
	}
private:
	/**
	  * @brief Consturtor of the Logger
	  *
	  * @return none
	*/ 
	Logger() {}
}; 

