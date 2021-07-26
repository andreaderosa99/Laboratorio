//
// Created by Andrea on 26/07/21.
//


#include "../FileLoader.h"
#include "../GUI.h"

#include "gtest/gtest.h"


TEST(fileLoaderTest, testListOfFiles){
    FileLoader loader;
    list<string> files;
    files.push_back("Document.doc");
    files.push_back("Note.txt");
    files.push_back("Document2.xlsx");
    ASSERT_NO_THROW(loader.loadFiles(files));
}

TEST(fileLoaderTest, testEmptyListOfFiles){
    FileLoader loader;
    list<string> files;
    ASSERT_THROW(loader.loadFiles(files), runtime_error);
}

TEST(fileLoaderTest, testLoading){
    FileLoader loader;
    loader.handleFile("Document.doc");
    ASSERT_EQ(loader.isLoaded(), true);
}

TEST(fileLoaderTest, testFailedLoading){
    FileLoader loader;
    loader.handleFile("File123.txt");
    ASSERT_EQ(loader.isLoaded(), false);
}
