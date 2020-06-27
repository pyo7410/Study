package com.springbook.biz.common;

import org.aspectj.lang.JoinPoint;
import org.aspectj.lang.annotation.Before;
import org.aspectj.lang.annotation.Pointcut;

public class LogAdvice {
	
	// AOP 실습
	/*
	public void printLog(JoinPoint jp) {
		System.out.println("[공통 로그] 비지니스 로직 수행 전 동작");
	}*/
	
	// 포인트컷 어노테이션 실습
	// 하나의 어드바이스 클래스 안에 여러개의 포인트컷을 사용할 수 있다.
	// 따라서 여러 포인트컷을 식별하기 위한 식별자로 참조 메소드를 이용한다.
	// 참조 메소드는 메소드 몸체가 비어있는, 즉 구현 로직이 없는 메소드이다.
	// 따라서 어떤 기능처리를 목적으로 하지 않고 단순히 포인트컷을 식별하는 이름으로만 사용한다.
	/*
	@Pointcut("execution(* com.springbook.biz..*Impl.*(..))")
	public void allPointcut() {}
	
	@Pointcut("execution(* com.springbook.biz..*Impl.get*(..))")
	public void getPointcut() {}
	*/
	
	// 어드바이스 설정 실습
	//포인트컷
	@Pointcut("execution(* com.springbook.biz..*Impl.*(..))")
	public void allPointcut() {}
	
	// 어드바이스
	@Before("allPointcut()")
	public void printLog() {
		System.out.println("[공통 로그] 비지니스 로직 수행 전 동작");
	}

}
