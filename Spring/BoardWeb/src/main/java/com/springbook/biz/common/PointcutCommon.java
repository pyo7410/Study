package com.springbook.biz.common;

import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Pointcut;

// 시스템에서 사용할 모든 포인트컷을 PointcutCommon 클래스에 등록하여 외부 pointcut을 참조할 수 있다.
// BeforeAdvice, AfterReturningAdvice 클래스 참고
@Aspect
public class PointcutCommon {
	@Pointcut("execution(* com.springbook.biz..*Impl.*(..))")
	public void allPointcut() {}
	
	@Pointcut("execution(* com.springbook.biz..*Impl.get*(..))")
	public void getPointcut() {}

}
