#include "CreaDXTKLib/CreaDXTKLib.h"
#include "CreaDXTKLib/GameManager.h"
#include "CreaDXTKLib/Scene.h"

CREADXTKLIB

using namespace CreaDXTKLib;

class Test : public Scene
{
public:

    virtual void Update(float _elapsedTime) override
    {
    }
    virtual void OnRender() override
    {
    }
};

void SetUp()
{
    SetStartScene<Test>();
}