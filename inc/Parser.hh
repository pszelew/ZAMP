#ifndef PARSER_HH
#define PARSER_HH

#include <string>
#include <sstream>
#include <cassert>
#include <cstdio>
#define LINESIZE 500

class Parser
{
    private:
        std::string cmdFile;
        std::string xmlFile;
    public:
        Parser(std::string cmd, std::string xml): cmdFile(cmd), xmlFile(xml) {} 
        bool parseCmd(std::istringstream & IStrm4Cmds);
        bool parseXML(std::istringstream & IStrm4Cmds);

};


#endif