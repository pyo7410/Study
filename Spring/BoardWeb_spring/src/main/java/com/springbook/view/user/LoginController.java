package com.springbook.view.user;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.springframework.web.servlet.ModelAndView;
import org.springframework.web.servlet.mvc.Controller;

import com.springbook.biz.user.UserVO;
import com.springbook.biz.user.impl.UserDAO;

public class LoginController implements Controller {
	
	@Override
	public ModelAndView handleRequest(HttpServletRequest request, HttpServletResponse response) {
		System.out.println("로그인 처리");

		// 1. 사용자 입력 정보 추출
		// 사용자가 입력한 아이디와 비밀번호를 request 객체로부터 추출한다.
		// 그리고 Model에 해당하는 UserVO와 UserDAO 객체를 이용하여 사용자 정보를 검색한다.
		// 그리고 검색결과로 UserVO 객체가 리턴되면 로그인 성공, null이 리턴되면 로그인 실패로 처리
		String id = request.getParameter("id");
		String password = request.getParameter("password");

		// 2. DB 연동 처리
		UserVO vo = new UserVO();
		vo.setId(id);
		vo.setPassword(password);

		UserDAO userDAO = new UserDAO();
		UserVO user = userDAO.getUser(vo);

		// 3. 화면 네비게이션
		// 화면 네비게이션 방법에는 포워드(Forward)방식과 리다이렉트(Redirect) 두 가지 방법이 있다.
		// 자세한 내용은 교재 248p 참고
		
		// "redirect:" 가 있다면 ViewResolver(presentation-layer.xml 참고)가 설정되어 있더라도 이를 무시하고 리다이렉트한다.
		ModelAndView mav = new ModelAndView();
		if (user != null) {
			mav.setViewName("redirect:getBoardList.do");
		} else {
			mav.setViewName("redirect:login.jsp");
		}
		return mav;
	}

}
