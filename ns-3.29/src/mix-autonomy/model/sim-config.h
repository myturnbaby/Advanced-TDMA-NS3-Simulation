#ifndef MIX_AUTONOMY_SIM_CONFIG
#define MIX_AUTONOMY_SIM_CONFIG

#include "ns3/core-module.h"
#include "ns3/mix-autonomy-common.h"

namespace ns3 {

// #define LOG_UNCOND(x) std::cout << x << std::endl

class SimulationConfig 
{
public:
    /** 任务id */
    uint32_t taskId = 0;
    /** 节点数量 */
    uint32_t nNodes = 0;
    /** 仿真时间 */
    uint32_t simTime = 600;
    /** Socket使用的端口 */
    uint32_t socketPort = 9;
    /** 物理层设置 */
    std::string phyMode = "OfdmRate6MbpsBW10MHz";
    /** 运动文件输入 */
    std::string mobilityInput = "";
    /** 日志文件 */
    std::string packetTraceFile = "";
    std::string eventTraceFile = "";
    std::string throughputTraceFile = "";

    /** 全局队列属性 */
    uint32_t txqCapacity = 100; // 发送队列大小

    void ParceCommandLineArguments (int argc, char **argv, bool doValidate);
    void ParceCommandLineArguments (int argc, char **argv) {
        ParceCommandLineArguments (argc, argv, true);
    };
    static SimulationConfig& Default ();
    void PrintConfiguration ();

private:
    void ConfigureCommandLineParams (CommandLine &cmd);
    void Validate ();
};

}

#endif