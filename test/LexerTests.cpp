#include "gtest/gtest.h"

#include "Lexer/Lexer.h"

#include "OperandFactory/OperandFactory.h"
#include "TokenFactory/TokenFactory.h"
#include "Tokens/CommentToken/CommentToken.h"
#include "Tokens/InstructionToken/InstructionToken.h"
#include "Tokens/ValueToken/ValueToken.h"

using ::testing::TestWithParam;
using ::testing::Values;

class LexerGetTokensTests :public ::testing::TestWithParam<std::tuple<std::string, std::vector<std::shared_ptr<IToken>>>> {
};

TEST_P(LexerGetTokensTests, GetTokens) {
    auto line = std::get<0>(GetParam());
    auto expected = std::get<1>(GetParam());

    Lexer lexer;

    auto res = lexer.getTokens(line);

    ASSERT_EQ(expected.size(), res.size());

    for (size_t i = 0; i < res.size(); i++)
    {
        ASSERT_EQ(expected[i]->getType(), res[i]->getType());

        switch (res[i]->getType())
        {
        case Instruction:
        {
            auto instructionToken1 = std::static_pointer_cast<InstructionToken>(expected[i]);
            auto instructionToken2 = std::static_pointer_cast<InstructionToken>(res[i]);
            ASSERT_EQ(instructionToken1->getContent(), instructionToken2->getContent());
        }
        break;
        case Value:
        {
            auto valueToken1 = std::static_pointer_cast<ValueToken>(expected[i]);
            auto valueToken2 = std::static_pointer_cast<ValueToken>(res[i]);
            ASSERT_EQ(valueToken1->getContent()->getType(), valueToken2->getContent()->getType());
            ASSERT_EQ(valueToken1->getContent()->toString(), valueToken2->getContent()->toString());
        }
        break;
        case Comment:
        {
            auto commentToken1 = std::static_pointer_cast<CommentToken>(expected[i]);
            auto commentToken2 = std::static_pointer_cast<CommentToken>(res[i]);
            ASSERT_EQ(commentToken1->getContent(), commentToken2->getContent());
        }
        break;
        }
    }
}

constexpr auto token = TokenFactory::createToken;
using tokens = std::vector<std::shared_ptr<IToken>>;

INSTANTIATE_TEST_CASE_P(
    UnitTestsLexer,
    LexerGetTokensTests,
    ::testing::Values(
        std::make_tuple("push", tokens(1, token(Instruction, "push"))),
        std::make_tuple("pop", tokens(1, token(Instruction, "pop"))),
        std::make_tuple("dump", tokens(1, token(Instruction, "dump"))),
        std::make_tuple("assert", tokens(1, token(Instruction, "assert"))),
        std::make_tuple("add", tokens(1, token(Instruction, "add"))),
        std::make_tuple("sub", tokens(1, token(Instruction, "sub"))),
        std::make_tuple("mul", tokens(1, token(Instruction, "mul"))),
        std::make_tuple("div", tokens(1, token(Instruction, "div"))),
        std::make_tuple("mod", tokens(1, token(Instruction, "mod"))),
        std::make_tuple("print", tokens(1, token(Instruction, "print"))),
        std::make_tuple("exit", tokens(1, token(Instruction, "exit"))),

        std::make_tuple("push int8(1)", tokens({ token(Instruction, "push"), token(Value, "int8(1)") })),
        std::make_tuple("push int16(1)", tokens({ token(Instruction, "push"), token(Value, "int16(1)") })),
        std::make_tuple("push int32(1)", tokens({ token(Instruction, "push"), token(Value, "int32(1)") })),
        std::make_tuple("push float(1.1)", tokens({ token(Instruction, "push"), token(Value, "float(1.1)") })),
        std::make_tuple("push double(1.1)", tokens({ token(Instruction, "push"), token(Value, "double(1.1)") }))
        //std::make_tuple("push ", tokens(1, token(Instruction, "push")))
    ));

class LexerGetTokensThrowTests :public ::testing::TestWithParam<std::tuple<std::string, std::exception_ptr>> {
};

TEST_P(LexerGetTokensThrowTests, GetTokens) {
    auto line = std::get<0>(GetParam());
    auto expected = std::get<1>(GetParam());

    Lexer lexer;

    if (expected)
    {
        EXPECT_ANY_THROW(
            {
                lexer.getTokens(line);
            });
    }
}

INSTANTIATE_TEST_CASE_P(
    UnitTestsLexer,
    LexerGetTokensThrowTests,
    ::testing::Values(
        std::make_tuple("push ", std::make_exception_ptr(std::exception(""))),
        std::make_tuple("push int32(1", std::make_exception_ptr(std::exception(""))),
        std::make_tuple("push int32(1.1)", std::make_exception_ptr(std::exception(""))),
        std::make_tuple("push int8()", std::make_exception_ptr(std::exception(""))),
        std::make_tuple("push float()", std::make_exception_ptr(std::exception(""))),

        std::make_tuple("", std::make_exception_ptr(std::exception("")))
    ));