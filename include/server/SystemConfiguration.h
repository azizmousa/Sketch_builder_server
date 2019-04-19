#ifndef SYSTEM_CONFIGURATION_
#define SYSTEM_CONFIGURATION_

#include <string>

class SystemConfiguration
{
private:
    SystemConfiguration();
    ~SystemConfiguration();

    static std::string SKETCH_BUILDER_UI_PATH;
    static std::string SKETCH_BUILDER_COMPILER_PATH;
    static std::string SKETCH_BUILDER_EQUALIZER_PAHT;
    static std::string SKETCH_BUILDER_GENERATOR_PATH;
    
public:
    
    static void setSystemUIPath(const std::string path);
    static void setSystemCompilerPath(const std::string path);
    static void setSystemEqualizerPath(const std::string path);
    static void setSystemCodeGeneratorPath(const std::string path);

    static std::string getSystemUIPath();
    static std::string getSystemCompilerPath();
    static std::string getSystemEqualizerPath();
    static std::string getSystemCodeGeneratorPath();

};
#endif