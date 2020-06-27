package com.springbook.biz.common;

import org.aspectj.lang.JoinPoint;
import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Before;
import org.aspectj.lang.annotation.Pointcut;
import org.springframework.stereotype.Service;

// �����̽� ������̼� �ǽ�
@Service
//@Aspect
public class BeforeAdvice {
	/*
	@Pointcut("execution(* com.springbook.biz..*Impl.*(..))")
	public void allPointcut(){} */
	
	//@Before("allPointcut()")
	// �ܺ� Pointcut ���� �ǽ�
	@Before("PointcutCommon.allPointcut()")
	public void beforeLog(JoinPoint jp) {
		// JoinPoint �ǽ�
		String method = jp.getSignature().getName();
		Object[] args = jp.getArgs();		
		System.out.println("[���� ó��]" + method + "() �޽�� ARGS ���� : " + args[0].toString());
		
		// System.out.println("[���� ó��] ����Ͻ� ���� ���� �� ����");
	}

}
