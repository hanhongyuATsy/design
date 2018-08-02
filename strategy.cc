#include<iostream>


class IStrategy
{
public:
    IStrategy(void);
    virtual ~IStrategy(void);
    virtual void Operator(void) = 0;
};

IStrategy::IStrategy(void)
{
}

IStrategy::~IStrategy(void)
{
}
class CBackDoor : public IStrategy
{
public:
    CBackDoor(void);
    ~CBackDoor(void);
    void Operator(void);
};

using std::cout;
using std::endl;
CBackDoor::CBackDoor(void)
{
}
CBackDoor::~CBackDoor(void)
{
}
void CBackDoor::Operator(void)
{
    cout << "找乔国老帮忙，让吴国太给孙权施压" << endl;
}

class GivenGreenLight : public IStrategy
{
public:
    GivenGreenLight(void);
    ~GivenGreenLight(void);
    void Operator(void);
};

GivenGreenLight::GivenGreenLight(void)
{
}
GivenGreenLight::~GivenGreenLight(void)
{
}
void GivenGreenLight::Operator(void)
{
    cout << "求吴国太给绿灯，放行" << endl;
}

class Context
{
public:
    Context(IStrategy *strategy);
    ~Context();
    void Operator(void);
private:
    IStrategy *m_strategy;
};

Context::Context(IStrategy *mStrategy)
{ 
    this->m_strategy = mStrategy;
}
Context::~Context(void)
{
    delete this->m_strategy;
}
void Context::Operator()
{
    this->m_strategy->Operator();
}

int main(int argc, char* argv[])
{
    Context *p_context;
    p_context = new Context(new CBackDoor());
    p_context->Operator();
    p_context = new Context(new GivenGreenLight());
    p_context->Operator();

    return 0;
}
