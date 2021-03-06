<?php
/*
 * Test sniff with short arrays.
 */

$good = [ 'value1', 'value2' ]; // Ok.

$query_vars = ['food']; // Bad, no spaces after opening and before closing parenthesis.

// Test for fixing of extra whitespace.
$test = [   1, 2     ];

$bad = [ 'key' => 'value' ]; // OK, one item single-line associative arrays are ok.

// Test for fixing nested associative arrays.
$bad = [ [ 'key1' => 'value1', 'key2' => ['sub1' => 1, 'sub2' => 2] ], $key3 => 'value3', [ 'value4', 10 => 'value5', ] ]; // Bad.

// Test for fixing mixed single & multi-line nested associative arrays.
$bad = [
	[ 'key1' => 'value1', ['sub1' => 1,'sub2' => 2,]],
	$key3 => 'value3',
	[ 'value4', 10 => 'value5' ]
]; // Bad.

// Test for fixing associative arrays with multiple values & line indented with whitespace.
		$bad = [ 'key1' => 'value1', 'key2' => 'value2', $key3 => 'value3', 'value4', 10 => 'value5' ]; // Bad.

// Test for fixing associative arrays with comments between values.
$bad = [ 'key1' => 'value1', /* comment */ 'key2' => 'value2' ]; // Bad.

// Test for fixing non-associative array with a nested associative array which *will* be fixed.
$bad = [ 'value1', 'value2', [ 'sub1' => 1, 'sub2' => 2 ], 'value4' ]; // Bad.

/*
 * Tests for empty array with space between parentheses.
 */
// OK.
$a = [];
$value = [ /* comment */ ];
$x = [
		// comment
	 ];

// Bad.
$value = [ ];
$value = [   ];
$x = [
	 ];

/*
 * Tests for multi-line arrays - closing brace on new line + array items each on new line.
 */
// OK.
$value = [
	1,
	2, /* Comment. */
	3,
];

$value = [
	1 => $one,
	2 => $two, // Comment.
	3 => $three, // Comment.
];

// Bad.
$value = [1,
	2 ,     3 ,
];

$value = [1 => $one,
	2 => $two , /* Comment. */ 3 => $three , ];

$value = [
	 '1'=> TRUE, FALSE,     '3' => 'aaa',];

$x = ['name' => 'test',
	 ];

$foo = [1
, 2];

$fields = [
	'value' => 'type'];

$bad = ['key' => 'value']; // Bad, spacing around parenthesis.
$bad = [     'key' => 'value'     ]; // Bad, spacing around parenthesis.

// @codingStandardsChangeSetting WordPress.Arrays.ArrayDeclarationSpacing allow_single_item_single_line_associative_arrays false

$bad = [ 'key' => 'value' ]; // Bad.
$bad = [ 'key1' => 'value1', 'key2' => 'value2' ]; // Bad.

// @codingStandardsChangeSetting WordPress.Arrays.ArrayDeclarationSpacing allow_single_item_single_line_associative_arrays true
