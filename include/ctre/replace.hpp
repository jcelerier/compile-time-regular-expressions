#ifndef CTRE__REPLACE__HPP
#define CTRE__REPLACE__HPP

// THIS FILE WAS GENERATED BY DESATOMAT TOOL, DO NOT MODIFY THIS FILE

#include "../ctll/grammars.hpp"

namespace ctre {

struct replace_gram {

// NONTERMINALS:
	struct capture2 {};
	struct capture_ext2 {};
	struct capture_ext {};
	struct escape {};
	struct insert {};
	struct replacement {};
	struct s {}; using _start = s;

// 'action' types:
	struct replacement_capture: ctll::action {};
	struct replacement_capture_push: ctll::action {};
	struct replacement_char_push: ctll::action {};
	struct rotate: ctll::action {};

// (q)LL1 function:
	using _others = ctll::neg_set<'$','\\','0','\x7B','\x7D','1','2','3','4','5','6','7','8','9'>;
	static constexpr auto rule(s, ctll::term<'\\'>) -> ctll::push<ctll::anything, escape, rotate>;
	static constexpr auto rule(s, ctll::term<'$'>) -> ctll::push<ctll::anything, insert, rotate>;
	static constexpr auto rule(s, ctll::set<'0','\x7B','\x7D','1','2','3','4','5','6','7','8','9'>) -> ctll::push<ctll::anything, replacement_char_push, replacement, rotate>;
	static constexpr auto rule(s, _others) -> ctll::push<ctll::anything, replacement_char_push, replacement, rotate>;
	static constexpr auto rule(s, ctll::epsilon) -> ctll::push<rotate>;

	static constexpr auto rule(capture2, ctll::epsilon) -> ctll::epsilon;
	static constexpr auto rule(capture2, ctll::set<'0','1','2','3','4','5','6','7','8','9'>) -> ctll::push<ctll::anything, replacement_capture_push, capture2>;
	static constexpr auto rule(capture2, ctll::set<'\x7B','\x7D'>) -> ctll::push<ctll::anything, replacement_char_push, replacement>;
	static constexpr auto rule(capture2, _others) -> ctll::push<ctll::anything, replacement_char_push, replacement>;
	static constexpr auto rule(capture2, ctll::set<'$','\\'>) -> ctll::reject;

	static constexpr auto rule(capture_ext2, ctll::term<'\x7D'>) -> ctll::epsilon;
	static constexpr auto rule(capture_ext2, ctll::set<'0','1','2','3','4','5','6','7','8','9'>) -> ctll::push<ctll::anything, replacement_capture_push, capture_ext2>;

	static constexpr auto rule(capture_ext, ctll::set<'1','2','3','4','5','6','7','8','9'>) -> ctll::push<ctll::anything, replacement_capture, capture_ext2>;
	static constexpr auto rule(capture_ext, ctll::term<'0'>) -> ctll::push<ctll::anything, replacement_capture>;

	static constexpr auto rule(escape, ctll::term<'\x7B'>) -> ctll::push<ctll::anything, capture_ext, ctll::term<'\x7D'>, replacement>;
	static constexpr auto rule(escape, ctll::set<'1','2','3','4','5','6','7','8','9'>) -> ctll::push<ctll::anything, replacement_capture, capture2>;
	static constexpr auto rule(escape, ctll::term<'0'>) -> ctll::push<ctll::anything, replacement_capture, replacement>;
	static constexpr auto rule(escape, ctll::set<'$','\\'>) -> ctll::push<ctll::anything, replacement_char_push, replacement>;

	static constexpr auto rule(insert, ctll::term<'\x7B'>) -> ctll::push<ctll::anything, capture_ext, ctll::term<'\x7D'>, replacement>;
	static constexpr auto rule(insert, ctll::set<'1','2','3','4','5','6','7','8','9'>) -> ctll::push<ctll::anything, replacement_capture, capture2>;
	static constexpr auto rule(insert, ctll::term<'0'>) -> ctll::push<ctll::anything, replacement_capture, replacement>;

	static constexpr auto rule(replacement, ctll::epsilon) -> ctll::epsilon;
	static constexpr auto rule(replacement, ctll::term<'\\'>) -> ctll::push<ctll::anything, escape>;
	static constexpr auto rule(replacement, ctll::term<'$'>) -> ctll::push<ctll::anything, insert>;
	static constexpr auto rule(replacement, ctll::set<'0','\x7B','\x7D','1','2','3','4','5','6','7','8','9'>) -> ctll::push<ctll::anything, replacement_char_push, replacement>;
	static constexpr auto rule(replacement, _others) -> ctll::push<ctll::anything, replacement_char_push, replacement>;

};

}

#endif //CTRE__REPLACE__HPP