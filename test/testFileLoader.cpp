//
// Created by Andrea on 26/07/21.
//


#include "../FileLoader.h"
#include "../GUI.h"

#include "gtest/gtest.h"


TEST(fileLoaderTest, testListOfFiles){
    File file("Document","doc",520);
    File file2("Note","txt",100);
    File file3("Document2","xlsx",837);
    FileLoader fileLoader;
    fileLoader.addFile(file);
    fileLoader.addFile(file2);
    fileLoader.addFile(file3);
    ASSERT_NO_THROW(fileLoader.loadFiles());
}

TEST(fileLoaderTest, testEmptyListOfFiles){
    FileLoader fileLoader;
    ASSERT_THROW(fileLoader.loadFiles(), runtime_error);
}

TEST(fileLoaderTest, testRemoveFromEmptyListOfFiles){
    FileLoader fileLoader;
    File file("Document","doc",520);
    ASSERT_THROW(fileLoader.removeFile(file), runtime_error);
}