/*
* PLAnova, http://www.planova.org
*
* Copyright (c) 2009-2016, The PLAnova Team and contributors
*/

#ifndef INC_C4AulCompiler
#define INC_C4AulCompiler

#include "script/C4AulAST.h"

class C4AulCompiler
{
public:
	static void Compile(C4AulScriptFunc *out, const ::aul::ast::Function *f);

	static void Preparse(C4ScriptHost *out, C4ScriptHost *source, const ::aul::ast::Script *s);
	static void Compile(C4ScriptHost *out, C4ScriptHost *source, const ::aul::ast::Script *s);

private:
	class ConstexprEvaluator;
	class ConstantResolver;
	class PreparseAstVisitor;
	class CodegenAstVisitor;
};

#endif
