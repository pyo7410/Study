package com.springbook.biz.common;

import org.aspectj.lang.JoinPoint;
import org.aspectj.lang.annotation.AfterReturning;
import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Pointcut;
import org.springframework.stereotype.Service;

import com.springbook.biz.user.UserVO;

// 어드바이스 어노테이션 실습
@Service
//@Aspect
public class AfterReturningAdvice {
	/*
	@Pointcut("execution(* com.springbook.biz..*Impl.get*(..))")
	public void getPointcut() {} */
	
	// pointcut 속성을 이용하여 포인트컷을 참조
	// returning 속성을 이용하여 바인드 변수를 지정, 반드시 바인드 변수명과 같아야한다.
	//@AfterReturning(pointcut="getPointcut()", returning="returnObj")
	// 외부 포인트컷 설정 실습
	@AfterReturning(pointcut="PointcutCommon.getPointcut()", returning="returnObj")
	public void afterLog(JoinPoint jp, Object returnObj) {
		// JoinPoint 실습
		// Object 타입의 변수는 바인드 변수라 한다.
		// 바인드 변수는 비즈니스 메소드가 리턴할 결괏값을 바인딩할 목적으로 사용, 어떤 값이 리턴될지 모르기 때문에 Object 타입으로 선언한다.
		String method = jp.getSignature().getName();
		if (returnObj instanceof UserVO) {
			UserVO user = (UserVO)returnObj;
			if (user.getRolo().equals("Admin")) {
				System.out.println(user.getName() + " 로그인(Adimin)");
			}
		}
		System.out.println("[사후 처리] " + method + "() 메소드 리턴값 : " + returnObj.toString());
		
		//System.out.println("[사후 처리] 비즈니스 로직 수행 후 동작");
	}

}
