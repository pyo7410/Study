package com.springbook.biz.common;

import org.aspectj.lang.JoinPoint;
import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Before;
import org.aspectj.lang.annotation.Pointcut;
import org.springframework.stereotype.Service;

// 어드바이스 어노테이션 실습
@Service
//@Aspect
public class BeforeAdvice {
	/*
	@Pointcut("execution(* com.springbook.biz..*Impl.*(..))")
	public void allPointcut(){} */
	
	//@Before("allPointcut()")
	// 외부 Pointcut 참조 실습
	@Before("PointcutCommon.allPointcut()")
	public void beforeLog(JoinPoint jp) {
		// JoinPoint 실습
		String method = jp.getSignature().getName();
		Object[] args = jp.getArgs();		
		System.out.println("[사전 처리]" + method + "() 메쏘드 ARGS 정보 : " + args[0].toString());
		
		// System.out.println("[사전 처리] 비즈니스 로직 수행 전 동작");
	}

}
