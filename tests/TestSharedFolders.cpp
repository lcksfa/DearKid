#include <gtest/gtest.h>
#include "sharedfolders/SharedFolderOpt.h"

struct SharedFolderTestF : public ::testing::Test
{
    void SetUp() override{
        opInstance = new SharedFolderOpt;
    }
    void TearDown() override{
        delete opInstance;
    }

    SharedFolderOpt* opInstance ;
};

TEST_F(SharedFolderTestF,Canpen)
{
    EXPECT_TRUE(opInstance->open());
}

TEST_F(SharedFolderTestF,Canclose)
{
    EXPECT_TRUE(opInstance->close());
}

TEST_F(SharedFolderTestF,ShowSubdirs)
{
    ASSERT_TRUE(opInstance->open());
    EXPECT_EQ(opInstance->getSubdirs().size(),6);
    EXPECT_TRUE(opInstance->close());
}