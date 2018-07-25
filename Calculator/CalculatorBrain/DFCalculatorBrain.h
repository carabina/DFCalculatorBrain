//
//  DFCalculatorBrain.h
//  Accouting
//
//  Created by wanghaojiao on 2018/3/11.
//  Copyright © 2018年 WANG Haojiao. All rights reserved.
//

#import <Foundation/Foundation.h>

//TYPEDEF
typedef NSString DFCalculatorOperator;
static DFCalculatorOperator* const DFCalculatorOperatorPlus = @"+";
static DFCalculatorOperator* const DFCalculatorOperatorMinus = @"-";
static DFCalculatorOperator* const DFCalculatorOperatorMultiply = @"×";
static DFCalculatorOperator* const DFCalculatorOperatorDivide = @"÷";

typedef void (^DFCalculatorBrainUpdatingDisplayBlock)(NSArray<NSString*>*);

@class DFCalculatorNumberFormatter;

//BRAIN
@interface DFCalculatorBrain : NSObject

//configuration
@property (nonatomic) BOOL isCurrency; //default NO
@property (nonatomic) NSInteger precision; //default 6
@property (nonatomic) NSInteger numberLengthLimit; //default 9
@property (nonatomic,strong) DFCalculatorNumberFormatter* formatter; //see class for detail
- (void)setDefaultValue:(NSDecimalNumber*)value;
- (void)clearInput;

//actions
- (BOOL)clickedDigit:(NSString*)digit;
- (BOOL)clickedOperator:(DFCalculatorOperator*)calculatorOperator;
- (BOOL)clickedDot;
- (BOOL)clickedDelete;

- (NSDecimalNumber*)getResult;//equals

//status
@property (nonatomic,copy) NSArray* calculatorStack;//will update whenever clicked. kvo supported
+ (NSDecimalNumber*)getResultFromStack:(NSArray<NSString*>*)stack;

//listening, with formated result from formatter
- (void)listenToStackDisplayChangeWithBlock:(DFCalculatorBrainUpdatingDisplayBlock)block;
- (void)stopListening;

@end
