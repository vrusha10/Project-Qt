#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "AssetMdbmanagerservice.h"

TEST(AssetMDbTest ,WhenDBIsConnectedThenISDBConnectionFunctionTrue)
{
    bool expectedDBConnection=true;

    AssetMdbmanagerservice obj(true);
    EXPECT_EQ(expectedDBConnection,obj.IsDBConnected());
}


