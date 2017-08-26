//term 42:了解typename的双重意义


/*****************  eg  1************************/
//bad
template <typename C>
void print2nd(const C & container)
{
	if (container.size() >= 2)
	{
		//编译器在解析template时遇到了嵌套从属名称，便假定不是类型
		C::const_iterator iter(container.begin());

	}
}


//current
template <typename C>
void print2nd(const C & container)
{
	if (container.size() >= 2)
	{
		//typename必须作为嵌套从属名称的前缀词，不过有例外情况
		typename C::const_iterator iter(container.begin());

	}
}