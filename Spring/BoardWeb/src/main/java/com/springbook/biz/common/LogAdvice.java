package com.springbook.biz.common;

import org.aspectj.lang.JoinPoint;
import org.aspectj.lang.annotation.Before;
import org.aspectj.lang.annotation.Pointcut;

public class LogAdvice {
	
	// AOP �ǽ�
	/*
	public void printLog(JoinPoint jp) {
		System.out.println("[���� �α�] �����Ͻ� ���� ���� �� ����");
	}*/
	
	// ����Ʈ�� ������̼� �ǽ�
	// �ϳ��� �����̽� Ŭ���� �ȿ� �������� ����Ʈ���� ����� �� �ִ�.
	// ���� ���� ����Ʈ���� �ĺ��ϱ� ���� �ĺ��ڷ� ���� �޼ҵ带 �̿��Ѵ�.
	// ���� �޼ҵ�� �޼ҵ� ��ü�� ����ִ�, �� ���� ������ ���� �޼ҵ��̴�.
	// ���� � ���ó���� �������� ���� �ʰ� �ܼ��� ����Ʈ���� �ĺ��ϴ� �̸����θ� ����Ѵ�.
	/*
	@Pointcut("execution(* com.springbook.biz..*Impl.*(..))")
	public void allPointcut() {}
	
	@Pointcut("execution(* com.springbook.biz..*Impl.get*(..))")
	public void getPointcut() {}
	*/
	
	// �����̽� ���� �ǽ�
	//����Ʈ��
	@Pointcut("execution(* com.springbook.biz..*Impl.*(..))")
	public void allPointcut() {}
	
	// �����̽�
	@Before("allPointcut()")
	public void printLog() {
		System.out.println("[���� �α�] �����Ͻ� ���� ���� �� ����");
	}

}
