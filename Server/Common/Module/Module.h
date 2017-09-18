#ifndef H_Module_INC
#define H_Module_INC
class Module
{

public:
    Module()
    {
    }

    virtual ~Module() {}

    virtual bool Awake()
    {
        return true;
    }

    virtual bool Init()
    {

        return true;
    }

    virtual bool AfterInit()
    {
        return true;
    }

    virtual bool CheckConfig()
    {
        return true;
    }

    virtual bool ReadyExecute()
    {
        return true;
    }

    virtual bool Execute()
    {
        return true;
    }

    virtual bool BeforeShut()
    {
        return true;
    }

    virtual bool Shut()
    {
        return true;
    }


 //   virtual NFIPluginManager* GetPluginManager() const
//    {
//        return pPluginManager;
//    }

//    std::string strName;

//protected:
//	NFIPluginManager* pPluginManager = NULL;
};
#endif
