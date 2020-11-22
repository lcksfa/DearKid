#include <gtest/gtest.h>
#include "paneitemgui/PaneItem.h"
#include <QtTest/QtTest> //for testing Gui
#include <QString>

class GPanelItemTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
        panelItem = new GPanelItem();
    }
    virtual void TearDown()
    {
        delete panelItem;
    }
    GPanelItem *panelItem;
};
TEST_F(GPanelItemTest, testInit)
{
}
// GUI testing using QtTest
//测试加
TEST_F(GPanelItemTest, testIncButton)
{
    panelItem->reset();
    QTest::mouseClick(panelItem->getIncreaseButton(), Qt::LeftButton);
    EXPECT_EQ(panelItem->getNumLabel()->text().toStdString(), ("1"));
}
//测试减少
TEST_F(GPanelItemTest, testDescButton)
{
    panelItem->setValue(1);
    EXPECT_EQ(panelItem->getNumLabel()->text().toStdString(), ("1"));
    QTest::mouseClick(panelItem->getDecreaseButton(), Qt::LeftButton);
    EXPECT_EQ(panelItem->getNumLabel()->text().toStdString(), ("0"));
}
//测试极限值 ，9为最大，继续加还是9
TEST_F(GPanelItemTest, testIncButtonEdge)
{
    panelItem->setValue(9);
    QTest::mouseClick(panelItem->getIncreaseButton(), Qt::LeftButton);
    EXPECT_EQ(panelItem->getNumLabel()->text().toStdString(), ("9"));
}
//测试极小值，0为最小，继续减少仍为0
TEST_F(GPanelItemTest, testDescButtonEdge)
{
    panelItem->setValue(0);
    QTest::mouseClick(panelItem->getDecreaseButton(), Qt::LeftButton);
    EXPECT_EQ(panelItem->getNumLabel()->text().toStdString(), ("0"));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    QApplication app(argc, argv);
    GPanelItem *panelItem = new GPanelItem();
    panelItem->show();
    RUN_ALL_TESTS();

    return app.exec();
}
