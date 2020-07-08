package com.springbook.view.user;

import javax.servlet.http.HttpSession;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;

//import javax.servlet.http.HttpServletRequest;
//import javax.servlet.http.HttpServletResponse;

//import org.springframework.web.servlet.ModelAndView;
//import org.springframework.web.servlet.mvc.Controller;

import com.springbook.biz.user.UserVO;
import com.springbook.biz.user.impl.UserDAO;

/*
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
*/

// 어노테이션 기반
@Controller
public class LoginController {
	// RequestMappring에 method를 추가하여 각기 다른 메소드별로 처리되게 할 수 있다.
	@RequestMapping(value="/login.do", method=RequestMethod.GET)
	public String loginView(UserVO vo)
	{
		System.out.println("로그인 화면으로 이동");
		// UserVO 객체를 login.jsp에서 사용한다.
		// 만약 .jsp 파일에서 이름을 UserVO가 아닌 다른 이름으로 변경하고 싶다면
		// public String loginView(@ModelAttribute("user") UserVO vo) 로 설정하면 된다.
		vo.setId("test");
		vo.setPassword("test123");
		return "login.jsp";
	}
	
	@RequestMapping(value="/login.do", method=RequestMethod.POST)
	public String login(UserVO vo, UserDAO userDAO, HttpSession session) {
		System.out.println("로그인 처리");
		
		if (vo.getId() == null || vo.getId().equals("")) {
			throw new IllegalArgumentException("아이디는 반드시 입력해야 합니다.");
		}
		
		UserVO user = userDAO.getUser(vo);
		
		if (userDAO.getUser(vo) != null)
		{
			session.setAttribute("userName", user.getName());
			return "getBoardList.do";
		}
		else
		{
			return "login.jsp";
		}
	}

}