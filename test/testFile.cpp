//
// Created by Andrea on 26/07/21.
//

#include "../File.h"
#include "gtest/gtest.h"

TEST(fileTest, testFile){
    ASSERT_NO_THROW(File file("Document.doc"));
}