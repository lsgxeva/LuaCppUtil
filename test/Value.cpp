
#include "TestUtil.hpp"

#include "LuaCpp/LuaValue.hpp"

using namespace luacpp;

class LuaReferenceTest : public LuaStateTest
{};

TEST_F(LuaReferenceTest, SetReference)
{
	LuaValue val = LuaValue::createValue(L, "TestTest");

	lua_pushnumber(L, 42.0);

	val.setReference(LuaReference::create(L));

	ASSERT_EQ(ValueType::NUMBER, val.getValueType());
	ASSERT_DOUBLE_EQ(42.0, val.getValue<double>());
}