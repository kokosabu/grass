#include <cutter.h>
#include <lexer.h>

#include <stdio.h>

void test_scan_null();
void test_scan_w();
void test_scan_W();
void test_scan_v();
void test_scan_w2();
void test_scan_w2W2();
void test_scan_head_comment();
void test_scan_tail_comment();
void test_scan_middle_comment();

void test_scan_null()
{
    FILE *program = fopen("test/sample/test/null.txt", "r");
    set_lexer(program);
    cut_assert_null(get_token());
}

void test_scan_w()
{
    FILE *program = fopen("test/sample/test/w.txt", "r");
    set_lexer(program);
    Token *token = get_token();
    cut_assert_true(token->type == SMALL_W);
    cut_assert_true(token->count == 1);
}

void test_scan_W()
{
    FILE *program = fopen("test/sample/test/W.txt", "r");
    set_lexer(program);
    Token *token = get_token();
    cut_assert_true(token->type == LARGE_W);
    cut_assert_true(token->count == 1);
}

void test_scan_v()
{
    FILE *program = fopen("test/sample/test/v.txt", "r");
    set_lexer(program);
    Token *token = get_token();
    cut_assert_true(token->type == SMALL_V);
    cut_assert_true(token->count == 1);
}

void test_scan_w2()
{
    FILE *program = fopen("test/sample/test/w2.txt", "r");
    set_lexer(program);
    Token *token = get_token();
    cut_assert_true(token->type == SMALL_W);
    cut_assert_true(token->count == 2);
}

void test_scan_w2W2()
{
    FILE *program = fopen("test/sample/test/w2W2.txt", "r");
    set_lexer(program);
    Token *token = get_token();
    cut_assert_true(token->type == SMALL_W);
    cut_assert_true(token->count == 2);
    token = get_token();
    cut_assert_true(token->type == LARGE_W);
    cut_assert_true(token->count == 2);
    token = get_token();
    cut_assert_null(token);
}

void test_scan_head_comment()
{
    FILE *program = fopen("test/sample/test/head_comment.txt", "r");
    set_lexer(program);
    Token *token = get_token();
    cut_assert_true(token->type == SMALL_W);
    cut_assert_true(token->count == 2);
    token = get_token();
    cut_assert_null(token);
}

void test_scan_tail_comment()
{
    FILE *program = fopen("test/sample/test/tail_comment.txt", "r");
    set_lexer(program);
    Token *token = get_token();
    cut_assert_true(token->type == SMALL_W);
    cut_assert_true(token->count == 2);
    token = get_token();
    cut_assert_null(token);
}

void test_scan_middle_comment()
{
    FILE *program = fopen("test/sample/test/middle_comment.txt", "r");
    set_lexer(program);
    Token *token = get_token();
    cut_assert_true(token->type == SMALL_W);
    cut_assert_true(token->count == 2);
    token = get_token();
    cut_assert_true(token->type == LARGE_W);
    cut_assert_true(token->count == 2);
    token = get_token();
    cut_assert_null(token);
}
