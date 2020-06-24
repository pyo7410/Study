package com.springbook.biz.common;

import org.aspectj.lang.ProceedingJoinPoint;
import org.aspectj.lang.annotation.Around;
import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Pointcut;
import org.springframework.stereotype.Service;
import org.springframework.util.StopWatch;

// 어드바이스 어노테이션 실습
@Service
//@Aspect
public class AroundAdvice {
	@Pointcut("execution(* com.springbook.biz..*Impl.*(..))")
	public void allPointcut() {}
	
	// Around 어드바이스는 다른 어드바이스와는 다르게 반드시 ProceedingJoinPoint 객체를 매개변수로 받아야 한다.
	// ProceedingJoinPoint 객체는 비즈니스 메소드를 호출하는 proceed() 메소드를 가지고 있으며 JoinPoint를 상속했다.
	@Around("allPointcut()")
	public Object aroundLog(ProceedingJoinPoint pjp) throws Throwable {
		// Before 어드바이스와 동일하게 동작
		// System.out.println("[Before]: 비즈니스 메소드 수행 전에 처리할 내용...");
		// 클라이언트의 요청을 가로챈 어드바이스는 클라이언트가 호출한 비즈니스 메소드를 호출하기 위해서
		// ProceedingJoinPoint 객체를 매개변수로 받아야 한다.
		// pjp.proceed()를 통해서 비즈니스 메소드를 호출할 수 있다.
		// Object returnObj = pjp.proceed();
		// After 어드바이스와 동일하게 동작
		// System.out.println("[AFTER]: 비즈니스 메소드 수행 후에 처리할 내용...");
		// return returnObj;

		// JoinPoint 실습
		String method = pjp.getSignature().getName();

		StopWatch stopWatch = new StopWatch();
		stopWatch.start();

		Object obj = pjp.proceed();

		stopWatch.stop();
		System.out.println(method + "() 메소드 수행에 걸린 시간 : " + stopWatch.getTotalTimeMillis() + "(ms)초");

		return obj;
	}

}
