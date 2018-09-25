
//Parameter description:
// mvcvCensusMin - computes minimum of 3 disparity costs values
// @param[in] in             - pointer to disparity costs
// @param[out] out           - array of disparity cost
// @param[out] outm          - array of minimum
// @param[in] width          - width of the input lines
// @return    Nothing




#include "gtest/gtest.h"
#include <censusMin3.h>
#include "censusMin3_asm_test.h"
#include "RandomGenerator.h"
#include "InputGenerator.h"
#include "UniformGenerator.h"
#include "TestEventListener.h"
#include "ArrayChecker.h"
#include <ctime>

using ::testing::TestWithParam;
using ::testing::Values;

#define PADDING 32

class mvcvCensusMin3KernelTest : public ::testing::TestWithParam< unsigned int > {
protected:

	virtual void SetUp()
	{
		randGen.reset(new RandomGenerator);
		uniGen.reset(new UniformGenerator);
		inputGen.AddGenerator(std::string("random"), randGen.get());
		inputGen.AddGenerator(std::string("uniform"), uniGen.get());
	}

	unsigned char *inLine1;
	unsigned char *outLineC;
	unsigned char *outLinemC;
	unsigned char *outLineAsm;
	unsigned char *outLinemAsm;
	unsigned int width;
	unsigned int disparities;

	InputGenerator inputGen;
	std::auto_ptr<RandomGenerator>  randGen;
	std::auto_ptr<UniformGenerator>  uniGen;
	ArrayChecker outputChecker;

	virtual void TearDown() {}
};

TEST_F(mvcvCensusMin3KernelTest, TestWidth16All0)
{
	width = 16;
	disparities = 3;
	inputGen.SelectGenerator("uniform");
	outLineC   = inputGen.GetEmptyLine(width + PADDING);
	outLinemC   = inputGen.GetEmptyLine(width + PADDING);
    outLineAsm = inputGen.GetEmptyLine(width + PADDING);
    outLinemAsm = inputGen.GetEmptyLine(width + PADDING);
	inputGen.FillLine(outLineC,  width + PADDING , 5);
	inputGen.FillLine(outLinemC,  width + PADDING , 5);
	inputGen.FillLine(outLineAsm,width + PADDING , 5);
	inputGen.FillLine(outLinemAsm,width + PADDING , 5);
	
	
	inLine1 = inputGen.GetLine((width * disparities), 0);
	
	mvcvCensusMin3(inLine1, outLineC + 16, outLinemC + 16, width);
	mvcvCensusMin3_asm_test(inLine1 , outLineAsm, outLinemAsm, width);
	
	RecordProperty("CyclePerPixel", mvcvCensusMin3CycleCount / (width ));

	//outputChecker.DumpArrays("refInput1", "refInput1.c", inLine1, width * disparities);
	//outputChecker.DumpArrays("outC", "outC.c", outLineC, width + PADDING);
	//outputChecker.DumpArrays("outAsm", "outAsm.c", outLineAsm, width + PADDING);
	
	
	outputChecker.CompareArrays(outLineC, outLineAsm, width + PADDING);
	outputChecker.CompareArrays(outLinemC, outLinemAsm, width + PADDING);
}
TEST_F(mvcvCensusMin3KernelTest, TestWidth16AllMAX)
{
	width = 16;
	disparities = 3;
	inputGen.SelectGenerator("uniform");
	outLineC   = inputGen.GetEmptyLine(width + PADDING);
	outLinemC   = inputGen.GetEmptyLine(width + PADDING);
    outLineAsm = inputGen.GetEmptyLine(width + PADDING);
    outLinemAsm = inputGen.GetEmptyLine(width + PADDING);
	inputGen.FillLine(outLineC,  width + PADDING , 5);
	inputGen.FillLine(outLinemC,  width + PADDING , 5);
	inputGen.FillLine(outLineAsm,width + PADDING , 5);
	inputGen.FillLine(outLinemAsm,width + PADDING , 5);
	
	
	inLine1 = inputGen.GetLine((width * disparities), 255);
	
	mvcvCensusMin3(inLine1, outLineC + 16, outLinemC + 16, width);
	mvcvCensusMin3_asm_test(inLine1 , outLineAsm, outLinemAsm, width);
	
	RecordProperty("CyclePerPixel", mvcvCensusMin3CycleCount / (width ));

	//outputChecker.DumpArrays("refInput1", "refInput1.c", inLine1, width * disparities);
	//outputChecker.DumpArrays("outC", "outC.c", outLineC, width + PADDING);
	//outputChecker.DumpArrays("outAsm", "outAsm.c", outLineAsm, width + PADDING);
	
	
	outputChecker.CompareArrays(outLineC, outLineAsm, width + PADDING);
	outputChecker.CompareArrays(outLinemC, outLinemAsm, width + PADDING);
}

TEST_F(mvcvCensusMin3KernelTest, TestRandomDATARandomWidth)
{
    disparities = 3;
	width = randGen->GenerateUInt(8, 1280, 8); //max width allowed to not overwrite the stack
	
	inputGen.SelectGenerator("uniform");
	outLineC   = inputGen.GetEmptyLine(width + PADDING);
	outLinemC   = inputGen.GetEmptyLine(width + PADDING);
    outLineAsm = inputGen.GetEmptyLine(width + PADDING);
    outLinemAsm = inputGen.GetEmptyLine(width + PADDING);
	inputGen.FillLine(outLineC,  width + PADDING , 5);
	inputGen.FillLine(outLinemC,  width + PADDING , 5);
	inputGen.FillLine(outLineAsm,width + PADDING , 5);
	inputGen.FillLine(outLinemAsm,width + PADDING , 5);
	
	inputGen.SelectGenerator("random");
	inLine1 = inputGen.GetLine((width * disparities), 0, 255);
	
	mvcvCensusMin3(inLine1, outLineC + 16, outLinemC + 16, width);
	mvcvCensusMin3_asm_test(inLine1 , outLineAsm, outLinemAsm, width);
	
	RecordProperty("CyclePerPixel", mvcvCensusMin3CycleCount / (width ));

	//outputChecker.DumpArrays("refInput1", "refInput1.c", inLine1, width * disparities);
	//outputChecker.DumpArrays("outC", "outC.c", outLineC, width + PADDING);
	//outputChecker.DumpArrays("outAsm", "outAsm.c", outLineAsm, width + PADDING);
	
	
	outputChecker.CompareArrays(outLineC, outLineAsm, width + PADDING);
	outputChecker.CompareArrays(outLinemC, outLinemAsm, width + PADDING);
}

TEST_F(mvcvCensusMin3KernelTest, TestRandomDATARandomWidth2)
{
    disparities = 3;
	width = randGen->GenerateUInt(960, 1280, 8); //max width allowed to not overwrite the stack
	
	inputGen.SelectGenerator("uniform");
	outLineC   = inputGen.GetEmptyLine(width + PADDING);
	outLinemC   = inputGen.GetEmptyLine(width + PADDING);
    outLineAsm = inputGen.GetEmptyLine(width + PADDING);
    outLinemAsm = inputGen.GetEmptyLine(width + PADDING);
	inputGen.FillLine(outLineC,  width + PADDING , 5);
	inputGen.FillLine(outLinemC,  width + PADDING , 5);
	inputGen.FillLine(outLineAsm,width + PADDING , 5);
	inputGen.FillLine(outLinemAsm,width + PADDING , 5);
	
	inputGen.SelectGenerator("random");
	inLine1 = inputGen.GetLine((width * disparities), 0, 255);
	
	mvcvCensusMin3(inLine1, outLineC + 16, outLinemC + 16, width);
	mvcvCensusMin3_asm_test(inLine1 , outLineAsm, outLinemAsm, width);
	
	RecordProperty("CyclePerPixel", mvcvCensusMin3CycleCount / (width ));

	//outputChecker.DumpArrays("refInput1", "refInput1.c", inLine1, width * disparities);
	//outputChecker.DumpArrays("outC", "outC.c", outLineC, width + PADDING);
	//outputChecker.DumpArrays("outAsm", "outAsm.c", outLineAsm, width + PADDING);
	
	
	outputChecker.CompareArrays(outLineC, outLineAsm, width + PADDING);
	outputChecker.CompareArrays(outLinemC, outLinemAsm, width + PADDING);
}
