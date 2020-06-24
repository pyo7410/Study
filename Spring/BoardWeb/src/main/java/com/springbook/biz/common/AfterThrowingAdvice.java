package com.springbook.biz.common;

import org.aspectj.lang.JoinPoint;
import org.aspectj.lang.annotation.AfterThrowing;
import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Pointcut;
import org.springframework.stereotype.Service;

// �����̽� ������̼� �ǽ�
@Service
//@Aspect
public class AfterThrowingAdvice {
	@Pointcut("execution(* com.springbook.biz..*Impl.*(..))")
	public void allPointcut() {}
	
	@AfterThrowing(pointcut="allPointcut()", throwing="exceptObj")
	public void exceptionLog(JoinPoint jp, Exception exceptObj) {
		// JoinPoint �ǽ�
		// exceptObj�� ���ε� �����̴�, ��� ���� ��ü�� ���ε� �ϱ����� ���� Ŭ���� �ֻ��� Ÿ���� Exception���� ����
		String method = jp.getSignature().getName();
		//System.out.println("[���� ó��] " + method + "() �޼ҵ� ���� �� �߻��� ���� �޽��� : " + exceptObj.getMessage());
		System.out.println(method + "() �޼ҵ� ���� �� �߻��� ���� �߻�!");
		
		if (exceptObj instanceof IllegalArgumentException) {
			System.out.println("�������� ���� �ԷµǾ����ϴ�.");
		} else if (exceptObj instanceof NumberFormatException) {
			System.out.println("���� ������ ���� �ƴմϴ�.");
		} else if (exceptObj instanceof Exception) {
			System.out.println("���� �߻��߽��ϴ�.");
		}
		
		//System.out.println("[���� ó��] ����Ͻ� ���� ���� �� ���� �߻�");
	}

}
