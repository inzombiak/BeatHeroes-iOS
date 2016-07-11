//
//  CircularGestureRecognizer.m
//  BeatHeroes-iOS
//
//  Created by Zareh on 5/9/16.
//  Copyright © 2016 Zareh. All rights reserved.
//

#import "CircularGestureRecognizer.h"
#import <UIKit/UIGestureRecognizerSubclass.h>

static const int ANGLE_CAP = 4;



@implementation CircularGestureRecognizer

CGFloat pointPairToBearingDegrees(CGPoint startingPoint,CGPoint secondPoint)
{
    CGPoint originPoint = CGPointMake(secondPoint.x - startingPoint.x, secondPoint.y - startingPoint.y); // get origin point to origin by subtracting end from start
    float bearingRadians = atan2f(originPoint.y, originPoint.x); // get bearing in radians
    float bearingDegrees = bearingRadians * (180.0 / M_PI); // convert to degrees
    bearingDegrees = (bearingDegrees > 0.0 ? bearingDegrees : (360.0 + bearingDegrees)); // correct discontinuity
    return bearingDegrees;
}


- (void)reset
{
    [super reset];
    
    m_lastAngle = 0;
    
    self.state = UIGestureRecognizerStatePossible;
}

// mirror of the touch-delivery methods on UIResponder
// UIGestureRecognizers aren't in the responder chain, but observe
// touches hit-tested to their view and their view's subviews
// UIGestureRecognizers receive touches before the view to which
// the touch was hit-tested
- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{
    [super touchesBegan:touches withEvent:event];
    
    if (touches.count > 1)
    {
        self.state = UIGestureRecognizerStateFailed;
        return;
    }
    
    m_firstClick = [[touches anyObject] locationInView:self.view];
}

- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event
{
    [super touchesMoved:touches withEvent:event];
    
    CGPoint currPoint =[[touches anyObject] locationInView:self.view];
    NSLog(@"First Point: %@, Curr Point: %@", NSStringFromCGPoint(m_firstClick), NSStringFromCGPoint(currPoint));
    CGFloat angle = pointPairToBearingDegrees(m_firstClick, currPoint);
    NSLog(@"Current angle is:%f, Prev angle was: %f", angle, m_lastAngle);
    m_difference = angle - m_lastAngle;
    if(fabs(m_difference) < ANGLE_CAP && !CGPointEqualToPoint(currPoint, m_firstClick))
    {
        NSLog(@"Failed circle, difference: %f", fabs(angle - m_lastAngle));
        self.state = UIGestureRecognizerStateFailed;
        return;
    }
    
    m_lastAngle = angle;
}

- (void) touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event
{
    [super touchesEnded:touches withEvent: event];

    self.state = UIGestureRecognizerStateRecognized;
    
    if(m_difference > 0)
        _isClockwise = true;
    else
        _isClockwise = false;
    
   NSLog(_isClockwise ? @"Yes" : @"No");
    
}

@end
