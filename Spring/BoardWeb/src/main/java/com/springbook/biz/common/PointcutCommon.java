package com.springbook.biz.common;

import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Pointcut;

// �ý��ۿ��� ����� ��� ����Ʈ���� PointcutCommon Ŭ������ ����Ͽ� �ܺ� pointcut�� ������ �� �ִ�.
// BeforeAdvice, AfterReturningAdvice Ŭ���� ����
@Aspect
public class PointcutCommon {
	@Pointcut("execution(* com.springbook.biz..*Impl.*(..))")
	public void allPointcut() {}
	
	@Pointcut("execution(* com.springbook.biz..*Impl.get*(..))")
	public void getPointcut() {}

}
