package com.springbook.biz.common;

import org.aspectj.lang.ProceedingJoinPoint;
import org.aspectj.lang.annotation.Around;
import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Pointcut;
import org.springframework.stereotype.Service;
import org.springframework.util.StopWatch;

// �����̽� ������̼� �ǽ�
@Service
//@Aspect
public class AroundAdvice {
	@Pointcut("execution(* com.springbook.biz..*Impl.*(..))")
	public void allPointcut() {}
	
	// Around �����̽��� �ٸ� �����̽��ʹ� �ٸ��� �ݵ�� ProceedingJoinPoint ��ü�� �Ű������� �޾ƾ� �Ѵ�.
	// ProceedingJoinPoint ��ü�� ����Ͻ� �޼ҵ带 ȣ���ϴ� proceed() �޼ҵ带 ������ ������ JoinPoint�� ����ߴ�.
	@Around("allPointcut()")
	public Object aroundLog(ProceedingJoinPoint pjp) throws Throwable {
		// Before �����̽��� �����ϰ� ����
		// System.out.println("[Before]: ����Ͻ� �޼ҵ� ���� ���� ó���� ����...");
		// Ŭ���̾�Ʈ�� ��û�� ����æ �����̽��� Ŭ���̾�Ʈ�� ȣ���� ����Ͻ� �޼ҵ带 ȣ���ϱ� ���ؼ�
		// ProceedingJoinPoint ��ü�� �Ű������� �޾ƾ� �Ѵ�.
		// pjp.proceed()�� ���ؼ� ����Ͻ� �޼ҵ带 ȣ���� �� �ִ�.
		// Object returnObj = pjp.proceed();
		// After �����̽��� �����ϰ� ����
		// System.out.println("[AFTER]: ����Ͻ� �޼ҵ� ���� �Ŀ� ó���� ����...");
		// return returnObj;

		// JoinPoint �ǽ�
		String method = pjp.getSignature().getName();

		StopWatch stopWatch = new StopWatch();
		stopWatch.start();

		Object obj = pjp.proceed();

		stopWatch.stop();
		System.out.println(method + "() �޼ҵ� ���࿡ �ɸ� �ð� : " + stopWatch.getTotalTimeMillis() + "(ms)��");

		return obj;
	}

}
