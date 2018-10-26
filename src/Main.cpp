#include "CreaDXTKLib/CreaDXTKLib.h"
#include "CreaDXTKLib/GameManager.h"
#include "Scene/GameScene.h"

CREA_DXTKLIB

using namespace CreaDXTKLib;
using namespace GFF::Scene;

void SetUp()
{
    SetStartScene<GameScene>();
}