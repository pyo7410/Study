package com.springbook.biz.common;

import org.aspectj.lang.JoinPoint;
import org.aspectj.lang.annotation.AfterReturning;
import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Pointcut;
import org.springframework.stereotype.Service;

import com.springbook.biz.user.UserVO;

// �����̽� ������̼� �ǽ�
@Service
//@Aspect
public class AfterReturningAdvice {
	/*
	@Pointcut("execution(* com.springbook.biz..*Impl.get*(..))")
	public void getPointcut() {} */
	
	// pointcut �Ӽ��� �̿��Ͽ� ����Ʈ���� ����
	// returning �Ӽ��� �̿��Ͽ� ���ε� ������ ����, �ݵ�� ���ε� ������� ���ƾ��Ѵ�.
	//@AfterReturning(pointcut="getPointcut()", returning="returnObj")
	// �ܺ� ����Ʈ�� ���� �ǽ�
	@AfterReturning(pointcut="PointcutCommon.getPointcut()", returning="returnObj")
	public void afterLog(JoinPoint jp, Object returnObj) {
		// JoinPoint �ǽ�
		// Object Ÿ���� ������ ���ε� ������ �Ѵ�.
		// ���ε� ������ ����Ͻ� �޼ҵ尡 ������ �ᱣ���� ���ε��� �������� ���, � ���� ���ϵ��� �𸣱� ������ Object Ÿ������ �����Ѵ�.
		String method = jp.getSignature().getName();
		if (returnObj instanceof UserVO) {
			UserVO user = (UserVO)returnObj;
			if (user.getRolo().equals("Admin")) {
				System.out.println(user.getName() + " �α���(Adimin)");
			}
		}
		System.out.println("[���� ó��] " + method + "() �޼ҵ� ���ϰ� : " + returnObj.toString());
		
		//System.out.println("[���� ó��] ����Ͻ� ���� ���� �� ����");
	}

}
