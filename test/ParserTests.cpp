#include "gtest/gtest.h"

#include "Parser/Parser.h"

#include "EvaluationStructure/EvaluationStructure.h"
#include "OperandFactory/OperandFactory.h"
#include "TokenFactory/TokenFactory.h"

using ::testing::TestWithParam;
using ::testing::Values;

class ParserParseTests :public ::testing::TestWithParam<std::tuple<std::vector<std::shared_ptr<IToken>>, std::shared_ptr<IAST>, std::exception_ptr>> {
};

TEST_P(ParserParseTests, Parse) {
    auto tokens = std::get<0>(GetParam());
    auto expected = std::get<1>(GetParam());
    auto exptr = std::get<2>(GetParam());

    Parser parser;

    if (exptr)
    {
        EXPECT_ANY_THROW(
            {
                parser.parse(tokens);
            });
        return;
    }
	
    auto res = parser.parse(tokens);

    auto t1 = std::static_pointer_cast<EvaluationStructure>(expected);
	auto t2 = std::static_pointer_cast<EvaluationStructure>(res);

    ASSERT_EQ(*t1, *t2);
}

constexpr auto token = TokenFactory::createToken;
using tokens = std::vector<std::shared_ptr<IToken>>;
constexpr auto operand = OperandFactory::createOperand;

const auto ast = [](eInstruction instruction, const IOperand* value, std::string comment){return std::make_shared<EvaluationStructure>(instruction, value, std::move(comment)); };
const auto createExptr = [](std::string message) {return std::make_exception_ptr(std::exception(message.c_str())); };

INSTANTIATE_TEST_CASE_P(
    UnitTestsParser,
    ParserParseTests,
    ::testing::Values(
        std::make_tuple(tokens(1, token(Instruction, "push")), ast(Push, nullptr, ""), createExptr("")),
        std::make_tuple(tokens(1, token(Instruction, "pop")), ast(Pop, nullptr, ""), nullptr),
        std::make_tuple(tokens(1, token(Instruction, "dump")), ast(Dump, nullptr, ""), nullptr),
        std::make_tuple(tokens(1, token(Instruction, "assert")), ast(Assert, nullptr, ""), createExptr("")),
        std::make_tuple(tokens(1, token(Instruction, "add")), ast(Add, nullptr, ""), nullptr),
        std::make_tuple(tokens(1, token(Instruction, "sub")), ast(Sub, nullptr, ""), nullptr),
        std::make_tuple(tokens(1, token(Instruction, "mul")), ast(Mul, nullptr, ""), nullptr),
        std::make_tuple(tokens(1, token(Instruction, "div")), ast(Div, nullptr, ""), nullptr),
        std::make_tuple(tokens(1, token(Instruction, "mod")), ast(Mod, nullptr, ""), nullptr),
        std::make_tuple(tokens(1, token(Instruction, "print")), ast(Print, nullptr, ""), nullptr),
        std::make_tuple(tokens(1, token(Instruction, "exit")), ast(Exit, nullptr, ""), nullptr),

        std::make_tuple(tokens({ token(Instruction, "push"), token(Value, "int8(1)") }), ast(Push, operand(Int8, "1"), ""), nullptr),
        std::make_tuple(tokens({ token(Instruction, "pop"), token(Value, "int8(1)") }), nullptr, createExptr("")),
        std::make_tuple(tokens({ token(Instruction, "dump"), token(Value, "int8(1)") }), nullptr, createExptr("")),
        std::make_tuple(tokens({ token(Instruction, "assert"), token(Value, "int8(1)") }), ast(Assert, operand(Int8, "1"), ""), nullptr),
        std::make_tuple(tokens({ token(Instruction, "add"), token(Value, "int8(1)") }), nullptr, createExptr("")),
        std::make_tuple(tokens({ token(Instruction, "sub"), token(Value, "int8(1)") }), nullptr, createExptr("")),
        std::make_tuple(tokens({ token(Instruction, "mul"), token(Value, "int8(1)") }), nullptr, createExptr("")),
        std::make_tuple(tokens({ token(Instruction, "div"), token(Value, "int8(1)") }), nullptr, createExptr("")),
        std::make_tuple(tokens({ token(Instruction, "mod"), token(Value, "int8(1)") }), nullptr, createExptr("")),
        std::make_tuple(tokens({ token(Instruction, "print"), token(Value, "int8(1)") }), nullptr, createExptr("")),
        std::make_tuple(tokens({ token(Instruction, "exit"), token(Value, "int8(1)") }), nullptr, createExptr("")),

        std::make_tuple(tokens({ token(Instruction, "push"), token(Value, "int8(1)"), token(Comment, ";123") }), ast(Push, operand(Int8, "1"), ";123"), nullptr),
        std::make_tuple(tokens({ token(Instruction, "pop"), token(Comment, ";123") }), ast(Pop, nullptr, ";123"), nullptr),
        std::make_tuple(tokens({ token(Comment, ";123") }), ast(None, nullptr, ";123"), nullptr),

        std::make_tuple(tokens({ token(Comment, ";123"), token(Comment, ";123") }), nullptr, createExptr("")),
        std::make_tuple(tokens({ token(Comment, ";123"), token(Instruction, "push"), token(Value, "int8(1)") }), nullptr, createExptr("")),
        std::make_tuple(tokens({ token(Instruction, "push"), token(Comment, ";123"), token(Value, "int8(1)") }), nullptr, createExptr("")),
        std::make_tuple(tokens({ token(Value, "int8(1)"), token(Instruction, "push"), token(Comment, ";123") }), nullptr, createExptr("")),

        std::make_tuple(tokens({}), nullptr, createExptr(""))
    ));
