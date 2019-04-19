#ifndef SYSTEM_CONFIGURATION_
#define SYSTEM_CONFIGURATION_

#include <string>

class SystemConfiguration
{
private:
    static std::string SKETCH_BUILDER_UI_PATH;
    static std::string SKETCH_BUILDER_COMPILER_PATH;
    static std::string SKETCH_BUILDER_EQUALIZER_PAHT;
    static std::string SKETCH_BUILDER_GENERATOR_PATH;
public:
    SystemConfiguration();
    ~SystemConfiguration();
    
    void setSystemUIPath(const std::string path);
    void setSystemCompilerPath(const std::string path);
    void setSystemEqualizerPath(const std::string path);
    void setSystemCodeGeneratorPath(const std::string path);

    std::string getSystemUIPath()const;
    std::string getSystemCompilerPath()const;
    std::string getSystemEqualizerPath()const;
    std::string getSystemCodeGeneratorPath()const;

};
#endif