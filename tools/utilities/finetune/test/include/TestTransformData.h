////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Project:  Embedded Learning Library (ELL)
//  File:     TestTransformData.h (finetune_test)
//  Authors:  Chuck Jacobs
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Main driver function
void TestTransformData();

// Individual tests
void TestRemovePadding();
void TestTransformDataWithModel();
void TestTransformDataWithSubmodel();
void TestTransformDataWithCachedSubmodel();
