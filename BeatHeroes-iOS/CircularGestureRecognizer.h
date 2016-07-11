//
//  CircularGestureRecognizer.h
//  BeatHeroes-iOS
//
//  Created by Zareh on 5/9/16.
//  Copyright © 2016 Zareh. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface CircularGestureRecognizer : UIGestureRecognizer
{
    CGFloat m_lastAngle;
    CGPoint m_firstClick;
    CGFloat m_difference;
}

@property bool isClockwise;

@end
